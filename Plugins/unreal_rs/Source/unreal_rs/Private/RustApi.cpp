// Fill out your copyright notice in the Description page of Project Settings.


#include "RustApi.h"

#include "core_api.h"

enum RustApiLogLevel
{
	Error = 1,
	Warn = 2,
	Info = 3,
	Trace = 4,
};

void LogMsg(const char* msg, int logLevel)
{
	const FString fMsg = FString(msg);
	const RustApiLogLevel level = static_cast<RustApiLogLevel>(logLevel);
	switch (level)
	{
	case Error:
		UE_LOG(LogTemp, Error, TEXT("%s"), *fMsg);
		break;
	case Warn:
		UE_LOG(LogTemp, Warning, TEXT("%s"), *fMsg);
		break;
	case Info:
		UE_LOG(LogTemp, Display, TEXT("%s"), *fMsg);
		break;
	case Trace:
		UE_LOG(LogTemp, Log, TEXT("%s"), *fMsg);
		break;
	}

}

void RustApi::InitRustEngine()
{
	BindDebugLogger(&LogMsg);
	SetRustLogLevel(5);
}