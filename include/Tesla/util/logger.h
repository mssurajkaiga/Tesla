#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
// Simple abstraction over fprintf for logging

#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif

class Logger {
private:
	FILE* log_file;
public:
	enum error_type{FATAL, WARNING};
	Logger(FILE* lf) : log_file(lf) {}
	Logger(const char* lf);
	~Logger();
	void log(error_type et, const char* log_data, va_list args);

	void log_fatal(const char* log_data, ...);
	void log_warning(const char* log_data, ...);
};

Logger::Logger(const char* lf) {
	errno_t err = fopen_s(&log_file, lf, "a");
	if (err) perror("Error opening file");
}

Logger::~Logger() {
	if (log_file != NULL) {
		fclose(log_file);
	}
}

inline void Logger::log(error_type et, const char* log_data, va_list args) {
	switch (et) {
	case WARNING:
		fprintf(log_file, "WARNING: ");
		break;
	case FATAL:
		fprintf(log_file, "FATAL: ");
		break;
	}
	fprintf(log_file, log_data, args);
	fprintf(log_file, "\n");
}

inline void Logger::log_fatal(const char* log_data, ...) {
	va_list args;
	va_start(args, log_data);
	fprintf(log_file, log_data, args);
	va_end(args);
	Logger::log(FATAL, log_data, args);
}

inline void Logger::log_warning(const char* log_data, ...) {
	va_list args;
	va_start(args, log_data);
	fprintf(log_file, log_data, args);
	va_end(args);
	Logger::log(WARNING, log_data, args);
}

#endif