#ifndef QT_PRACTICE_LOG_WIDGET_H
#define QT_PRACTICE_LOG_WIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QTimer>
#include <QHBoxLayout>

#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <mutex>
#include "glog/logging.h"
class LogWidget : public QWidget, public google::LogSink
{
	Q_OBJECT;

public:
	LogWidget(QWidget *parent = 0);
	virtual ~LogWidget();

public:
	virtual void send(google::LogSeverity severity, const char* full_filename,
		const char* base_filename, int line, const struct ::tm* tm_time, const char* message, size_t message_len);

	public Q_SLOTS:
	void refresh();

private:
	QTextBrowser *log_widget_;
	QTimer timer_;
	std::mutex mutex_;

	typedef std::pair<std::string, google::LogSeverity> MessageType;
	std::vector<MessageType> message_vec_;

	const int MAXIMUM_BLOCK_COUNT;
	const int REFESH_TIME;
};

#endif//QT_PRACTICE_LOG_WIDGET_H