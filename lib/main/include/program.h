#pragma once

class Program final
{
public:
	Program() = default;
	~Program() = default;
	Program(const Program& other) = delete;
	Program& operator=(const Program& other) = delete;
	Program(Program&& other) = delete;
	Program& operator=(Program&& other) = delete;

	void start();
};