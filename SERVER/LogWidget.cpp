#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "LogWidget.h"
#include <iomanip>

LogWidget::LogWidget(QWidget *parent /*= 0*/) : QWidget(parent),
MAXIMUM_BLOCK_COUNT(10000), REFESH_TIME(100)
{
	QHBoxLayout *layout = new QHBoxLayout();
	layout->setMargin(0);
	setLayout(layout);

	//采用QPlainTextEdit显示日志信息
	log_widget_ = new QTextBrowser(this);
	//log_widget_->setMaximumBlockCount(MAXIMUM_BLOCK_COUNT);
	log_widget_->setReadOnly(true);
	layout->addWidget(log_widget_);

	//定时器，定时刷新日志
	QObject::connect(&timer_, SIGNAL(timeout()), this, SLOT(refresh()));
	timer_.start(REFESH_TIME);

	//添加到glog的转发容器中
	google::AddLogSink(this);

}

LogWidget::~LogWidget()
{
	timer_.stop();
	QObject::disconnect(&timer_, SIGNAL(timeout()), this, SLOT(refresh()));

	google::RemoveLogSink(this);
}

void LogWidget::refresh()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (!message_vec_.empty())
	{
		for (const auto &message : message_vec_)
		{
			log_widget_->append(QString::fromStdString(message.first.c_str()));
		}
	}
	message_vec_.clear();
}

void LogWidget::send(google::LogSeverity severity, const char* full_filename,
	const char* base_filename, int line, const struct ::tm* tm_time, const char* message, size_t message_len)
{
	std::ostringstream message_stream;
	message_stream.fill('0');

	message_stream << "[" << google::LogSeverityNames[severity][0]
		<< std::setw(2) << 1 + tm_time->tm_mon
		<< std::setw(2) << tm_time->tm_mday
		<< ' '
		<< std::setw(2) << tm_time->tm_hour << ':'
		<< std::setw(2) << tm_time->tm_min << ':'
		<< std::setw(2) << tm_time->tm_sec
		<< ' '
		<< full_filename << ':' << line << "] ";

	message_stream << std::string(message, message_len);
	std::string message_str = message_stream.str();

	std::lock_guard<std::mutex> lock(mutex_);
	message_vec_.push_back(MessageType(message_str, severity));
}
