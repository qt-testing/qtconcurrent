#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QThread>
#include <QtConcurrent>
#include <iostream>

long double factorial(int value)
{
	QElapsedTimer timer;

	timer.start();

	long double result = 1.0;

	for (int i = 1; i <= value; i++) {
		result *= i;
	}

	qint64 elapsedTime = timer.nsecsElapsed();

	qDebug() << "Elapsed time is " << elapsedTime << ". Thread id is " << QThread::currentThreadId();

	return result;
}

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	int value = 100;
	long double result = factorial(value);

	std::cout << "Factorial of " << value <<" is " << result << std::endl;

	for (int i = 0; i < 10; i++) {
		QtConcurrent::run(factorial, value);
	}

	return 0;
}