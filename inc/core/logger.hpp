#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>

// log file
namespace core::log
{
enum Type
{
  INFO,
  ERROR,
  WARNING
};

static inline const char *getErrorType(Type type)
{
  switch (type)
  {
    case INFO:
      return "INFO";
    case ERROR:
      return "ERROR";
    case WARNING:
      return "WARNING";
  }
  return "UNKNOWN";
}

inline void log(Type type, const char *desc, int errortype = 0)
{
  std::cerr << getErrorType(type) << " ERROR"
            << ((errortype) ? std::format("({})", errortype) : "") << ": "
            << desc << std::endl;
}

inline void info(const char *desc, int codeerror = 0)
{
  log(Type::INFO, desc, codeerror);
}

inline void error(const char *desc, int codeerror = 0)
{
  log(Type::ERROR, desc, codeerror);
}

inline void warning(const char *desc, int codeerror = 0)
{
  log(Type::WARNING, desc, codeerror);
}
};  // namespace core::log

#endif  // LOGGER_HPP