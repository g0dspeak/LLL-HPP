#ifndef TESTS_PERSISTANCE_FIXTURE_HPP
#define TESTS_PERSISTANCE_FIXTURE_HPP

#include <gtest/gtest.h>
#include <asio/io_context.hpp>
#include <config/config.hpp>
#include <persistance/create_component.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <thread>
#include <chrono>
#include <stdlib.h>

namespace
{
using namespace ::nexuspool;

class Persistance_fixture : public ::testing::Test
{
public:

	Persistance_fixture()
	{
		m_logger = spdlog::stdout_color_mt("logger");
		m_logger->set_level(spdlog::level::debug);
		m_persistance_component = persistance::create_component(m_logger, m_config);
	}

protected:

	std::shared_ptr<spdlog::logger> m_logger;
	config::Persistance_config m_config{ config::Persistance_type::sqlite, "test.db"};
	persistance::Component::Uptr m_persistance_component;

	void create_test_db()
	{
		system("create_test_sqlite.py");
		system("create_test_data.py");
	}

	void TearDown() override
	{
		spdlog::drop("logger");
	}
};

}
#endif