#include "text.h"
#include<iostream>


text::text()
{
	std::cout << "创建了test" << std::endl;
}


text::~text()
{
	std::cout << "析构了test" << std::endl;
}
void text::run()
{
	std::cout << "调用了run函数" << std::endl;
}
