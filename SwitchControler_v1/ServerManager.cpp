/*
 * ServerManager.cpp
 *
 *  Created on: 6 thg 2, 2017
 *      Author: MyPC
 */

#include "ServerManager.h"

ServerManager::ServerManager() {
	// TODO Auto-generated constructor stub
	server = new ESP8266WebServer(ModuleSettings::getInstance()->getServerPort());
	server->on("/favicon.png",[&](){ServerManager::handlerFile(200, MimePNG, favicon_png,  sizeof(favicon_png), GZIP_DISABLE,BROWSER_CACHE_DAYS);});
	server->on("/js/jquery.min.js.gz", [&](){ServerManager::handlerFile(200, MimeCss, jquery_3_1_0_min_js_gz, sizeof(jquery_3_1_0_min_js_gz), GZIP_ENABLE, BROWSER_CACHE_DAYS);});
	server->on("/js/md5.min.js.gz", [&](){ServerManager::handlerFile(200, MimeCss, md5_min_js_gz, sizeof(md5_min_js_gz), GZIP_ENABLE, BROWSER_CACHE_DAYS);});
	server->on("/js/bootstrap.min.js.gz", [&](){ServerManager::handlerFile(200, MimeCss, bootstrap_min_js_gz, sizeof(bootstrap_min_js_gz), GZIP_ENABLE, BROWSER_CACHE_DAYS);});
	server->on("/css/bootstrap.min.css.gz", [&](){ServerManager::handlerFile(200, MimeCss, bootstrap_min_css_gz, sizeof(bootstrap_min_css_gz), GZIP_ENABLE, BROWSER_CACHE_DAYS);});
	server->on("/css/bootstrap-theme.min.css.gz", [&](){ServerManager::handlerFile(200, MimeCss, bootstrap_theme_min_css_gz, sizeof(bootstrap_theme_min_css_gz), GZIP_ENABLE, BROWSER_CACHE_DAYS);});

	server->on("/login.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, login_html, sizeof(login_html), GZIP_ENABLE, LOGIN_UNREQUIRE);});

	server->on("/js/language-vi.js",[&](){ServerManager::handlerFile(200, MimeTypeJS, language_vi, sizeof(language_vi), GZIP_DISABLE, BROWSER_CACHE_DAYS);});
	server->on("/js/main.js",[&](){ServerManager::handlerFile(200, MimeTypeJS, main_js, sizeof(main_js), GZIP_DISABLE, BROWSER_CACHE_DAYS);});
	server->on("/css/skeleton.css",[&](){ServerManager::handlerFile(200, MimeCss, skeleton_css, sizeof(skeleton_css), GZIP_DISABLE, BROWSER_CACHE_DAYS);});
	server->on("/css/normalize.css",[&](){ServerManager::handlerFile(200, MimeCss, normalize_css, sizeof(normalize_css), GZIP_DISABLE, BROWSER_CACHE_DAYS);});
	server->on("/css/main.css",[&](){ServerManager::handlerFile(200, MimeCss, main_css, sizeof(main_css), GZIP_DISABLE, BROWSER_CACHE_DAYS);});

	server->on("/js/configs.js",std::bind(&ServerManager::handlerGetConfigs, this));


	server->on("/network.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, network_html, sizeof(network_html), GZIP_DISABLE, LOGIN_REQUIRE);});

	server->on("/admin.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, admin_html, sizeof(admin_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/gpio.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, gpio_html, sizeof(gpio_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/prog.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, prog_html, sizeof(prog_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/general.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, general_html, sizeof(general_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/time.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, time_html, sizeof(time_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/email.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, email_html, sizeof(email_html), GZIP_DISABLE, LOGIN_REQUIRE);});
	server->on("/device.html",[&](){ServerManager::handlerFileLogined(200, MimeHtml, device_html, sizeof(device_html), GZIP_DISABLE, LOGIN_REQUIRE);});



	server->on("/",std::bind(&ServerManager::handlerRoot, this));
	server->on("/command",std::bind(&ServerManager::handlerCommand, this));
	server->on("/login",std::bind(&ServerManager::handlerLogin, this));
	server->on("/logout.html",std::bind(&ServerManager::handlerLogout, this));
	server->on("/logout",std::bind(&ServerManager::handlerLogout, this));
	server->on("/ajax",std::bind(&ServerManager::handlerAjax, this));

	server->onNotFound ( std::bind(&ServerManager::handlerNotFound, this) );
	server->begin();
	DBGF("HTTP Server Started");
}

ServerManager::~ServerManager() {
	// TODO Auto-generated destructor stub
	delete server;
}

void ServerManager::handlerRoot() {
	int role = getUserRole();
	if(role < 1){
		redirect("/login.html");
	}else{
		redirect("/admin.html");
	}
}


void ServerManager::handlerFile(int code, const char* content_type, PGM_P data, size_t contentLength, bool bGzip, unsigned long expire) {
	getSession();
	sendHeaderGzip(contentLength, bGzip, expire);
	server->send_P(code, content_type, data, contentLength);
}

void ServerManager::handlerFileLogined(int code, const char* content_type,
		PGM_P data, size_t contentLength, bool bGzip, bool needLogined) {
	getSession();
	if(needLogined && (getUserRole() < 1)){
		redirect("/login.html");
		return;
	}
	sendHeaderGzip(contentLength, bGzip, 0);
	server->send_P(code, content_type, data, contentLength);
}

void ServerManager::loop() {
	server->handleClient();
}

void ServerManager::handlerNotFound() {

}

void ServerManager::handlerCommand() {
	server->sendHeader("Connection", "close");
	server->send(200, MimeJson, Commander::getInstance()->process(server->arg("plain")));
}

int ServerManager::checkLogined() {
	int role = getUserRole();
	if(role < 1){
		redirect("/login.html");
	}
	return role;
}

void ServerManager::sendHeaderGzip(size_t contentLength, bool gzip, unsigned long expire) {
	if(gzip) server->sendHeader("Content-Encoding", "gzip");
	server->sendHeader("Connection", "close");
	if(expire){
		char buf[34];
		time_t t = now();
		// if time is accurate, then try to send a Date header Wed, 15 Nov 1995 06:25:24 GMT
		if ( year(t)>2015 ) {
			char dow[5];
			strncpy(dow,dayShortStr(weekday(t)),4);
			dow[3] = 0;
			sprintf(buf,"%s, %02u %s %04u %02u:%02u:%02u GMT",dow,day(t),monthShortStr(month(t)),year(t),hour(t),minute(t),second(t));
			server->sendHeader("Date",buf);
		}
		sprintf(buf,"max-age=%lu",expire);
		server->sendHeader("Cache-Control",buf);
		sprintf(buf,"%lu",(unsigned long)contentLength);
		server->sendHeader("ETag",buf);
	}
}

int ServerManager::getUserRole() {
	return Session::getInstance()->getUserRole(getSession());
}
void ServerManager::handlerLogin() {
	getSession();
	int role = getUserRole();
	if(role > 0){
		redirect("/");
		return;
	}
	if(!server->hasArg("userid")||!server->hasArg("password")){
		server->sendHeader("Connection", "close");
		server->send_P(200, MimeHtml, login_html);
	}else{
		String username = server->arg("userid");
		String password = server->arg("password");
		if(username == ModuleSettings::getInstance()->getUserDevice()){
			if(password == ModuleSettings::getInstance()->getPassDevice()){
				setSession(USER_ROLE);
				server->send(200, MimeHtml, "ok");
			}else{
				server->sendHeader("Connection", "close");
				server->send(200, MimeHtml, "wrongp");
			}
		}else{
			server->sendHeader("Connection", "close");
			server->send(200, MimeHtml, "wrongu");
		}
	}
}

void ServerManager::handlerLogout() {
	String ss = getSession();
	DBGF0("Logout => ");
	DBG2F("Delete Session: ", ss);
	Session::getInstance()->deleteSS(ss);
	redirect("/login.html");
}

void ServerManager::redirect(const char* path) {
	if(!path)	return;
	String url;
	url = "http://";
	url += getHost();
	url += path;

	String content;
	content.reserve(250);

	content = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta http-equiv=\"refresh\" content=\"0; URL='";
	content += url;
	content += "'\" />\n<title>Redirecting</title>\n</head>\n<body onload=\"window.location='";
	content += url;
	content += "';\">\n</body>\n</html>";

	server->sendHeader("Location",url);
	server->sendHeader("Cache-Control","no-cache");
	server->sendHeader("Pragma","no-cache");
	DBGF("Redirect...");
	server->send(302,"text/html",content);
}

String ServerManager::getHost() {
	String host;
	host.reserve(24);
	host = server->header("Host");
	if ( host.length()<1 ) {
	host=WiFi.localIP().toString();
	if ( ModuleSettings::getInstance()->getServerPort()!=80 ) {
	  host += ":";
	  host += ModuleSettings::getInstance()->getServerPort();
	}
	}
	DBG2F("Host: ",host);
	return host;
}

void ServerManager::setSession(int role) {
	String cookie;
	String ssName= Session::getInstance()->createSS(role);
	cookie = "espid=";
	cookie += ssName;
	cookie += "; Path=/; Max-Age=";
	cookie += SESSION_EXPIRE_TIME;
	DBG2F("Set-Cookie: ", cookie);
	server->sendHeader("Set-Cookie",cookie);
}

String ServerManager::getSession() {
	int numH = server->headers();
	for(int i = 0; i<numH; i++){
		DBG2F0("header ",i);
		DBG2F0(" : ",server->headerName(i));
		DBG2F(" == ",server->header(i));
	}
	String cookie = server->header("Cookie");
	DBGF0("Client Cookie: ");
	DBG(server->header("Cookie"));
	return cookie;
}

void ServerManager::handlerGetConfigs() {
	getSession();
	sendHeaderGzip(sizeof(bootstrap_min_css_gz), GZIP_DISABLE, 0);
	String config = FPSTR(configs_language_js);
	config.replace("$cf1$","vi");

	config+= FPSTR(configs_nework_js);
	config.replace("$cf1$",ModuleSettings::getInstance()->getWifiSSID());
	config.replace("$cf2$",ModuleSettings::getInstance()->getWifiPassword());
	config.replace("$cf3$",String(ModuleSettings::getInstance()->getDHCP()));
	config.replace("$cf4$",ModuleSettings::getInstance()->getStaticIP());
	config.replace("$cf5$",ModuleSettings::getInstance()->getMask());
	config.replace("$cf6$",ModuleSettings::getInstance()->getGateway());
	config.replace("$cf7$",String(ModuleSettings::getInstance()->getServerPort()));
	server->send(200, MimeTypeJS, config);
}

void ServerManager::handlerBootstrapTheme() {
}

void ServerManager::handlerBootstrapJS() {
}

void ServerManager::handlerMD5JS() {
}

void ServerManager::handlerJqueryJS() {
}

void ServerManager::handlerAjax() {
	getSession();
	if(getUserRole()>0){
		server->sendHeader("Connection", "close");
		server->send(200, MimeJson, Commander::getInstance()->process(server->arg("plain")));
	}else{
		server->sendHeader("Connection", "close");
		server->send_P(200, MimeJson, JsonFalse, sizeof(JsonFalse));
	}
}

void ServerManager::handlerNetworkSettings() {

}