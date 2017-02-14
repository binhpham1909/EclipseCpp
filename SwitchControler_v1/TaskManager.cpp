/*
 * TaskManager.cpp
 *
 *  Created on: 13 thg 2, 2017
 *      Author: MyPC
 */

#include "TaskManager.h"

bool true_condition() {
	return true;
}

TaskManager::TaskManager() {
	// TODO Auto-generated constructor stub
	_isTasksRunning = false;
	_runTask = -1;
	_tasks = new TTask[1];
	_totalTasks = 0;
}

TaskManager::~TaskManager() {
	// TODO Auto-generated destructor stub
	delete _tasks;

}

void TaskManager::addTask(String name, void (*func)(), bool (*conditionFunc)(), TMode mode, unsigned long timer) {
	TTask job;
	strncpy(job.name,name.c_str(),15);
	job.func = func;
	job.conditionFunc = conditionFunc;
	job.mode = mode;
	job.timer = timer;
	job.nextTime = millis();
	job.isRunning = true;
	DBG2F("Add task: ", name);
	insertTask(job);
}

void TaskManager::addTask(String name, void (*func)(), bool (*conditionFunc)(), unsigned long timer) {
	TTask job;
	strncpy(job.name,name.c_str(),15);
	job.func = func;
	job.conditionFunc = conditionFunc;
	job.mode = Repeat;
	job.timer = timer;
	job.nextTime = millis();
	job.isRunning = true;
	DBG2F("Add task: ", name);
	insertTask(job);
}

void TaskManager::addTask(String name, void (*func)(), TMode mode,
		unsigned long timer) {
	TTask job;
	strncpy(job.name,name.c_str(),15);
	job.func = func;
	job.conditionFunc = true_condition;
	job.mode = mode;
	job.timer = timer;
	job.nextTime = millis();
	job.isRunning = true;
	DBG2F("Add task: ", name);
	insertTask(job);
}

void TaskManager::addTask(String name, void (*func)(), unsigned long timer) {
	TTask job;
	strncpy(job.name,name.c_str(),15);
	job.func = func;
	job.conditionFunc = true_condition;
	job.mode = Repeat;
	job.timer = timer;
	job.nextTime = millis();
	job.isRunning = true;
	DBG2F("Add task: ", name);
	insertTask(job);
}

void TaskManager::insertTask(TTask& job) {
	_totalTasks++;
	TTask *tasks = new TTask[_totalTasks];
	if (_totalTasks > 1)
		for (long long i = 0; i < _totalTasks - 1; i++){
			tasks[i] = _tasks[i];
		}
	tasks[_totalTasks - 1] = job;
	DBG2F("Interval (ms): ", job.timer);
	DBG2F("Nexttime (ms): ", job.nextTime);
	delete _tasks;
	_tasks = tasks;
	DBGF(".>> done");
}

void TaskManager::startTasks(){
	_runTask = 0;
	_isTasksRunning = true;
}

void TaskManager::loop() {
	if(_isTasksRunning){
		TTask job = _tasks[_runTask];
		unsigned long curr = millis();
		if(job.isRunning){
		//	DBG2F0("Run task ", _runTask);
		//	DBG2F(" : ", job.name);
			if((job.mode == Repeat)&&(curr >= job.nextTime)){
				if(job.conditionFunc()){
					job.func();
					_tasks[_runTask].nextTime = curr + job.timer;
					//DBG2F("Interval (ms): ", job.timer);
					//DBG2F("Nexttime (ms): ", job.nextTime);
				}
			}
		//	DBG2F0("Done task \"", job.name);
		//	DBG2F("\" in (ms) : ", millis() - curr);
			if(job.mode == Once)	_tasks[_runTask].isRunning = false;
		}
		_runTask++;
		if(_runTask >= _totalTasks)	_runTask = 0;	// index trong c++ bat dau tu 0
	}
}

void TaskManager::pauseTasks() {
	_isTasksRunning = false;
}


void TaskManager::resumeTasks() {
	_isTasksRunning = true;
}

void TaskManager::stopTasks() {
	_runTask = -1;
	_isTasksRunning = false;
}
void TaskManager::restartTasks() {
	_runTask = 0;
	_isTasksRunning = true;
}
