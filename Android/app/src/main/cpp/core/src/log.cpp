#include "headers.hpp"

unsigned long getTheadId() {
    std::hash<std::thread::id> hash_thread_number;
    return hash_thread_number(std::this_thread::get_id()); // threadid 转成 unsigned long
}

std::string dateAndTime() {
    auto now = std::chrono::system_clock::now();
    //通过不同精度获取相差的毫秒数
    uint64_t dis_millseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()
                               -
                               std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() * 1000;
    time_t tt = std::chrono::system_clock::to_time_t(now);
    auto time_tm = localtime(&tt);
    char strTime[128] = {0};
    sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d:%03d", time_tm->tm_year + 1900,
            time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
            time_tm->tm_min, time_tm->tm_sec, (int) dis_millseconds);
    return strTime;
}

void do_log(enum log_level level,
            const char *sfile,
            int sline,
            const char *sfunc,
            const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char msg[MAX_LOG_BUF_SIZE] = {0};
    vsprintf(msg, fmt, ap);
    va_end(ap);

    // 日志等级
    switch (level)
    {
        case INFO:
            LOG_INFO("[%s] [INFO] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
        case WARN:
            LOG_WARN("[%s] [WARN] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
        case ERROR:
            LOG_ERROR("[%s] [ERROR] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
        case DEBUG:
            LOG_DEBUG("[%s] [DEBUG] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
        case VERB:
            LOG_VERBOSE("[%s] [VERB] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
        default:
            printf("[%s] [INFO] [%s:%d] (%s) <%lu> %s\n", dateAndTime().c_str(), sfile,
                    sline, sfunc, getTheadId(), msg);
            break;
    }
}