#ifndef PRETTYPRINT_HPP
#define PRETTYPRINT_HPP

#include <iostream>
#include <string>
#include <string_view>
#include <any>
#include <vector>
#include <typeinfo>
#include <compare>
#include <initializer_list>
#include <queue>
#include <unordered_map>
#include <map>
#include <deque>
#include <memory>
#include <set>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <sstream>
#include <optional>
#include <filesystem>
#include <variant>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <regex>

namespace {

	const std::regex regex_1("\\s+[}]\\s*,");
	const std::regex regex_2("([\\w,]+)\\s+[}]");
	const std::regex regex_3("[\\n\\r]+[}]");
	const std::regex regex_4("^[\\n\\r\\s]+[{][\\n\\r\\s]+");
	class NestedPrinter {
	public:
		std::string anyToString(std::any&& value) {
			if (value.type() == typeid(std::string_view)) {
				std::string s = { std::any_cast<std::string_view>(value).begin(), std::any_cast<std::string_view>(value).end() };
				return "\"" + s + "\"";

			}
			if (value.type() == typeid(const char*)) {
				std::string s = std::any_cast<const char*> (value);
				return s;
			}
			if (value.type() == typeid(char)) {
				std::string s;
				s += std::any_cast<char> (value);
				return s;
			}
			if (value.type() == typeid(char*)) {
				std::string s = std::any_cast<char*> (value);
				return "\"" + s + "\"";
			}
			if (value.type() == typeid(std::string)) {
				return "\"" + std::any_cast<std::string> (value) + "\"";
			}
			if (value.type() == typeid(std::string&)) {
				return "\"" + std::string(std::any_cast<std::string&> (value)) + "\"";
			}
			if (value.type() == typeid(bool)) {
				if (std::any_cast<bool> (value))
					return "True";
				else
					return "False";
			}
			if (value.type() == typeid(std::nullptr_t)) {
				return "nullptr";
			}
			if (value.type() == typeid(void)) {
				return "void";
			}
			if (value.type() == typeid(void*)) {
				return "void*";
			}
			if (value.type() == typeid(wchar_t)) {
				return  std::to_string(std::any_cast<wchar_t> (value));
			}
			if (value.type() == typeid(int8_t)) {
				return  std::to_string(std::any_cast<int8_t> (value));
			}
			if (value.type() == typeid(int8_t*)) {
				return  std::to_string(*(std::any_cast<int8_t*> (value)));
			}
			if (value.type() == typeid(int16_t)) {
				return  std::to_string(std::any_cast<int16_t> (value));
			}
			if (value.type() == typeid(int16_t*)) {
				return  std::to_string(*(std::any_cast<int16_t*> (value)));
			}
			if (value.type() == typeid(int32_t)) {
				return  std::to_string(std::any_cast<int32_t> (value));
			}
			if (value.type() == typeid(int32_t*)) {
				return  std::to_string(*(std::any_cast<int32_t*> (value)));
			}
			if (value.type() == typeid(int64_t)) {
				return  std::to_string(std::any_cast<int64_t> (value));
			}
			if (value.type() == typeid(int64_t*)) {
				return  std::to_string(*(std::any_cast<int64_t*> (value)));
			}
			if (value.type() == typeid(uint8_t)) {
				return  std::to_string(std::any_cast<uint8_t> (value));
			}
			if (value.type() == typeid(uint8_t*)) {
				return  std::to_string(*(std::any_cast<uint8_t*> (value)));
			}
			if (value.type() == typeid(uint16_t)) {
				return  std::to_string(std::any_cast<uint16_t> (value));
			}
			if (value.type() == typeid(uint16_t*)) {
				return  std::to_string(*(std::any_cast<uint16_t*> (value)));
			}
			if (value.type() == typeid(uint32_t)) {
				return  std::to_string(std::any_cast<uint32_t> (value));
			}
			if (value.type() == typeid(uint32_t*)) {
				return  std::to_string(*(std::any_cast<uint32_t*> (value)));
			}
			if (value.type() == typeid(uint64_t)) {
				return  std::to_string(std::any_cast<uint64_t> (value));
			}
			if (value.type() == typeid(uint64_t*)) {
				return  std::to_string(*(std::any_cast<uint64_t*> (value)));
			}
			if (value.type() == typeid(int_least8_t)) {
				return  std::to_string(std::any_cast<int_least8_t> (value));
			}
			if (value.type() == typeid(int_least8_t*)) {
				return  std::to_string(*(std::any_cast<int_least8_t*> (value)));
			}
			if (value.type() == typeid(int_least16_t)) {
				return  std::to_string(std::any_cast<int_least16_t> (value));
			}
			if (value.type() == typeid(int_least16_t*)) {
				return  std::to_string(*(std::any_cast<int_least16_t*> (value)));
			}
			if (value.type() == typeid(int_least32_t)) {
				return  std::to_string(std::any_cast<int_least32_t> (value));
			}
			if (value.type() == typeid(int_least32_t*)) {
				return  std::to_string(*(std::any_cast<int_least32_t*> (value)));
			}
			if (value.type() == typeid(int_least64_t)) {
				return  std::to_string(std::any_cast<int_least64_t> (value));
			}
			if (value.type() == typeid(int_least64_t*)) {
				return  std::to_string(*(std::any_cast<int_least64_t*> (value)));
			}
			if (value.type() == typeid(uint_least8_t)) {
				return  std::to_string(std::any_cast<uint_least8_t> (value));
			}
			if (value.type() == typeid(uint_least8_t*)) {
				return  std::to_string(*(std::any_cast<uint_least8_t*> (value)));
			}
			if (value.type() == typeid(uint_least16_t)) {
				return  std::to_string(std::any_cast<uint_least16_t> (value));
			}
			if (value.type() == typeid(uint_least16_t*)) {
				return  std::to_string(*(std::any_cast<uint_least16_t*> (value)));
			}
			if (value.type() == typeid(uint_least32_t)) {
				return  std::to_string(std::any_cast<uint_least32_t> (value));
			}
			if (value.type() == typeid(uint_least32_t*)) {
				return  std::to_string(*(std::any_cast<uint_least32_t*> (value)));
			}
			if (value.type() == typeid(uint_least64_t)) {
				return  std::to_string(std::any_cast<uint_least64_t> (value));
			}
			if (value.type() == typeid(uint_least64_t*)) {
				return  std::to_string(*(std::any_cast<uint_least64_t*> (value)));
			}
			if (value.type() == typeid(int_fast8_t)) {
				return  std::to_string(std::any_cast<int_fast8_t> (value));
			}
			if (value.type() == typeid(int_fast8_t*)) {
				return  std::to_string(*(std::any_cast<int_fast8_t*> (value)));
			}
			if (value.type() == typeid(int_fast16_t)) {
				return  std::to_string(std::any_cast<int_fast16_t> (value));
			}
			if (value.type() == typeid(int_fast16_t*)) {
				return  std::to_string(*(std::any_cast<int_fast16_t*> (value)));
			}
			if (value.type() == typeid(int_fast32_t)) {
				return  std::to_string(std::any_cast<int_fast32_t> (value));
			}
			if (value.type() == typeid(int_fast32_t*)) {
				return  std::to_string(*(std::any_cast<int_fast32_t*> (value)));
			}
			if (value.type() == typeid(int_fast64_t)) {
				return  std::to_string(std::any_cast<int_fast64_t> (value));
			}
			if (value.type() == typeid(int_fast64_t*)) {
				return  std::to_string(*(std::any_cast<int_fast64_t*> (value)));
			}
			if (value.type() == typeid(uint_fast8_t)) {
				return  std::to_string(std::any_cast<uint_fast8_t> (value));
			}
			if (value.type() == typeid(uint_fast8_t*)) {
				return  std::to_string(*(std::any_cast<uint_fast8_t*> (value)));
			}
			if (value.type() == typeid(uint_fast16_t)) {
				return  std::to_string(std::any_cast<uint_fast16_t> (value));
			}
			if (value.type() == typeid(uint_fast16_t*)) {
				return  std::to_string(*(std::any_cast<uint_fast16_t*> (value)));
			}
			if (value.type() == typeid(uint_fast32_t)) {
				return  std::to_string(std::any_cast<uint_fast32_t> (value));
			}
			if (value.type() == typeid(uint_fast32_t*)) {
				return  std::to_string(*(std::any_cast<uint_fast32_t*> (value)));
			}
			if (value.type() == typeid(uint_fast64_t)) {
				return  std::to_string(std::any_cast<uint_fast64_t> (value));
			}
			if (value.type() == typeid(uint_fast64_t*)) {
				return  std::to_string(*(std::any_cast<uint_fast64_t*> (value)));
			}
			if (value.type() == typeid(intmax_t)) {
				return  std::to_string(std::any_cast<intmax_t> (value));
			}
			if (value.type() == typeid(intmax_t*)) {
				return  std::to_string(*(std::any_cast<intmax_t*> (value)));
			}
			if (value.type() == typeid(uintmax_t)) {
				return  std::to_string(std::any_cast<uintmax_t> (value));
			}
			if (value.type() == typeid(uintmax_t*)) {
				return  std::to_string(*(std::any_cast<uintmax_t*> (value)));
			}
			if (value.type() == typeid(float_t)) {
				return  std::to_string(std::any_cast<float_t> (value));
			}
			if (value.type() == typeid(float_t*)) {
				return  std::to_string(*(std::any_cast<float_t*> (value)));
			}
			if (value.type() == typeid(double_t)) {
				return  std::to_string(std::any_cast<double_t> (value));
			}
			if (value.type() == typeid(double_t*)) {
				return  std::to_string(*(std::any_cast<double_t*> (value)));
			}
			else {
				try {
					return std::any_cast<std::string>(value);

				}
				catch (std::exception& e) {
					return e.what();
				}
				return value.type().name() + std::string(" COULD NOT BE CONVERTED");
			}
		}

		std::string  any_to_string(auto value, int counter = 0)
			requires requires { std::is_arithmetic<decltype(value)>::value; (!(value._sv)); }
		{
			try {
				return std::to_string(value);
			}
			catch (std::exception& e) {
				return e.what();
			}
		}
		std::string  any_to_string(const std::string& value, int counter = 0) {
			try {
				return "\"" + std::string(value) + "\"";
			}
			catch (std::exception& e) {
				return e.what();
			}
		}
		std::string  any_to_string(const std::string_view value, int counter = 0) {
			try {
				return "\"" + std::string{ value.begin(), value.end() } + "\"";
			}
			catch (std::exception& e) {
				return e.what();
			}
		}
		std::string  any_to_string(const char* value, int counter = 0) {
			try {
				return "\"" + std::string(value) + "\"";
			}
			catch (std::exception& e) {
				return e.what();
			}
		}
		std::string  any_to_string(auto value, int counter = 0) {
			try {
				return anyToString(value);
			}
			catch (std::exception& e) {
				return e.what();
			}
		}

		template <typename T>
		std::string  any_to_string(const std::vector<T>& value, const std::string& prefix, const std::string& suffix, int counter = 0) {
			std::string result = prefix;
			std::string tempstring = "";

			for (auto item : value) {
				tempstring.clear();
				try {
					tempstring.append(any_to_string(item, counter + 1));
				}
				catch (std::exception& e) {
					tempstring.append(e.what());
				}
				result.append(tempstring);

				result.append(std::string(", "));
			}
			result.resize(result.size() - 2);
			result.append(suffix);
			return result;
		}


		template <typename T, typename N>
		std::string  any_to_string(const std::multimap<T, N>& value, const std::string& prefix, const std::string& suffix, int counter = 0) {
			std::string result = prefix;
			std::string tempstring = "";
			for (auto item : value) {
				tempstring = (any_to_string(item, counter + 1));
				result.append(tempstring);

				result.append(std::string(", "));
			}
			result.resize(result.size() - 2);
			result.append(suffix);
			return result;
		}
		template <typename T, typename N>
		std::string  any_to_string(const std::unordered_multimap<T, N>& value, const std::string& prefix, const std::string& suffix, int counter = 0) {
			std::string result = prefix;
			std::string tempstring = "";
			for (auto item : value) {
				tempstring = (any_to_string(item, counter + 1));
				result.append(tempstring);

				result.append(std::string(", "));

			}
			result.resize(result.size() - 2);
			result.append(suffix);
			return result;
		}

		template <typename T, typename N>
		std::string  any_to_string(const std::map<T, N>& value, const std::string& prefix, const std::string& suffix, int counter = 0) {
			std::string result = prefix;
			std::string tempstring = "";
			for (auto item : value) {
				tempstring = (any_to_string(item, counter + 1));
				result.append(tempstring);

				result.append(std::string(", "));
			}
			result.resize(result.size() - 2);
			result.append(suffix);
			return result;
		}
		template <typename T>
		std::string  any_to_string(const std::vector<T>& value, int counter = 0) {
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(value, myprefix, std::string(mysuffix), counter + 1);
		}


		template <typename T, size_t N>
		std::string  any_to_string(const std::array<T, N>& value, int counter = 0) {
			std::vector<T> tmpvec{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tmpvec, myprefix, mysuffix), counter + 1;

		}
		template <typename T, typename N>
		std::string  any_to_string(const std::pair<T, N>& value, int counter = 0) {
			std::string invecj = any_to_string(value.second);
			return any_to_string(value.first) + " : " + any_to_string(value.second);
		}
		template <typename T, typename N>
		std::string  any_to_string(const std::map<T, N>& value, int counter = 0) {
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(value, myprefix, mysuffix, counter + 1);

		}
		template <typename T, typename N>
		std::string  any_to_string(const std::unordered_map<T, N>& value, int counter = 0) {
			std::map<T, N> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::deque<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}

		template <typename T>
		std::string  any_to_string(const std::queue<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}

		template <typename T>
		std::string  any_to_string(const std::priority_queue<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}

		template <typename T>
		std::string  any_to_string(const std::list<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::forward_list<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::set<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::unordered_set<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::unordered_multiset<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);

			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);
		}
		template <typename T>
		std::string  any_to_string(const std::multiset<T>& value, int counter = 0) {
			std::vector<T> tempmap{ value.begin(), value.end() };
			std::string myprefix = _get_prefix(counter);
			std::string mysuffix = _get_suffix(counter);
			return any_to_string(tempmap, myprefix, mysuffix, counter + 1);

		}

		std::string _get_prefix(int counter) {
			std::string result = "\n";
			for (int i = 0; i < counter; i++) {
				result += " ";
			}
			result += "{";
			return result;

		}
		std::string _get_suffix(int counter) {
			std::string result = "";
			for (int i = 0; i < counter; i++) {
				result += " ";
			}
			result += "}\n";
			return result;
		}
	};

	bool is_whitespace(char c) {
		return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
	}
}


namespace prettyprinter {
	namespace printcolors {
		// Reset
		static constexpr std::string_view Color_Off = "\033[0m";// Text Reset
		// Regular Colors
		static constexpr std::string_view Black = "\033[0;30m";// Black
		static constexpr std::string_view Red = "\033[0;31m";// Red
		static constexpr std::string_view Green = "\033[0;32m";// Green
		static constexpr std::string_view Yellow = "\033[0;33m";// Yellow
		static constexpr std::string_view Blue = "\033[0;34m";// Blue
		static constexpr std::string_view Purple = "\033[0;35m";// Purple
		static constexpr std::string_view Cyan = "\033[0;36m";// Cyan
		static constexpr std::string_view White = "\033[0;37m";// White
		// Bold
		static constexpr std::string_view BBlack = "\033[1;30m";// Black
		static constexpr std::string_view BRed = "\033[1;31m";// Red
		static constexpr std::string_view BGreen = "\033[1;32m";// Green
		static constexpr std::string_view BYellow = "\033[1;33m";// Yellow
		static constexpr std::string_view BBlue = "\033[1;34m";// Blue
		static constexpr std::string_view BPurple = "\033[1;35m";// Purple
		static constexpr std::string_view BCyan = "\033[1;36m";// Cyan
		static constexpr std::string_view BWhite = "\033[1;37m";// White
		// Underline
		static constexpr std::string_view UBlack = "\033[4;30m";// Black
		static constexpr std::string_view URed = "\033[4;31m";// Red
		static constexpr std::string_view UGreen = "\033[4;32m";// Green
		static constexpr std::string_view UYellow = "\033[4;33m";// Yellow
		static constexpr std::string_view UBlue = "\033[4;34m";// Blue
		static constexpr std::string_view UPurple = "\033[4;35m";// Purple
		static constexpr std::string_view UCyan = "\033[4;36m";// Cyan
		static constexpr std::string_view UWhite = "\033[4;37m";// White
		// Background
		static constexpr std::string_view On_Black = "\033[40m";// Black
		static constexpr std::string_view On_Red = "\033[41m";// Red
		static constexpr std::string_view On_Green = "\033[42m";// Green
		static constexpr std::string_view On_Yellow = "\033[43m";// Yellow
		static constexpr std::string_view On_Blue = "\033[44m";// Blue
		static constexpr std::string_view On_Purple = "\033[45m";// Purple
		static constexpr std::string_view On_Cyan = "\033[46m";// Cyan
		static constexpr std::string_view On_White = "\033[47m";// White
		// High Intensity
		static constexpr std::string_view IBlack = "\033[0;90m";// Black
		static constexpr std::string_view IRed = "\033[0;91m";// Red
		static constexpr std::string_view IGreen = "\033[0;92m";// Green
		static constexpr std::string_view IYellow = "\033[0;93m";// Yellow
		static constexpr std::string_view IBlue = "\033[0;94m";// Blue
		static constexpr std::string_view IPurple = "\033[0;95m";// Purple
		static constexpr std::string_view ICyan = "\033[0;96m";// Cyan
		static constexpr std::string_view IWhite = "\033[0;97m";// White
		// Bold High Intensty
		static constexpr std::string_view BIBlack = "\033[1;90m";// Black
		static constexpr std::string_view BIRed = "\033[1;91m";// Red
		static constexpr std::string_view BIGreen = "\033[1;92m";// Green
		static constexpr std::string_view BIYellow = "\033[1;93m";// Yellow
		static constexpr std::string_view BIBlue = "\033[1;94m";// Blue
		static constexpr std::string_view BIPurple = "\033[1;95m";// Purple
		static constexpr std::string_view BICyan = "\033[1;96m";// Cyan
		static constexpr std::string_view BIWhite = "\033[1;97m";// White
		// High Intensty backgrounds
		static constexpr std::string_view On_IBlack = "\033[0;100m";// Black
		static constexpr std::string_view On_IRed = "\033[0;101m";// Red
		static constexpr std::string_view On_IGreen = "\033[0;102m";// Green
		static constexpr std::string_view On_IYellow = "\033[0;103m";// Yellow
		static constexpr std::string_view On_IBlue = "\033[0;104m";// Blue
		static constexpr std::string_view On_IPurple = "\033[10;95m";// Purple
		static constexpr std::string_view On_ICyan = "\033[0;106m";// Cyan
		static constexpr std::string_view On_IWhite = "\033[0;107m";// White
	}

	NestedPrinter np;
	template <typename T>
	std::string repr(T val) {

		std::string crazyNestedMap_string = np.any_to_string(val);
		bool foundcolon = false;
		for (int i = 0; i < crazyNestedMap_string.size(); i++) {
			if (crazyNestedMap_string[i] == ':') {
				foundcolon = true;
				continue;
			}
			if (foundcolon) {
				if (is_whitespace(crazyNestedMap_string[i])) {

					crazyNestedMap_string[i] = ' ';
				}
				else {
					foundcolon = false;
				}
			}

		}

		for (int i = 0; i < crazyNestedMap_string.size(); i++) {
			if (crazyNestedMap_string[i] == '}') {
				if ((i + 2) < crazyNestedMap_string.size()) {
					if ((crazyNestedMap_string[i + 1] == '\n') && (crazyNestedMap_string[i + 2] == ',')) {
						crazyNestedMap_string[i + 1] = ' ';
					}

				}
			}


		}
		int last_whitespace_counter = 1;
		std::string outvecj;
		for (int i = 0; i < crazyNestedMap_string.size(); i++) {
			if ((last_whitespace_counter == 0) && (crazyNestedMap_string[i] == ' ')) {
				outvecj += ' ';
				last_whitespace_counter += 1;
				continue;
			}
			else if ((last_whitespace_counter != 0) && ((crazyNestedMap_string[i] == ' '))) {
				last_whitespace_counter += 1;
				continue;
			}
			last_whitespace_counter = 0;
			outvecj += crazyNestedMap_string[i];
		}



		std::string new_s = std::regex_replace(crazyNestedMap_string, regex_1, "},");
		std::string new_s3 = std::regex_replace(new_s, regex_2, "$1}");
		std::string new_s4 = std::regex_replace(new_s3, regex_3, "}");
		std::string new_s5 = std::regex_replace(new_s4, regex_4, "{", std::regex_constants::format_first_only);
		return new_s5;
	}
	template <typename T>
	std::string print_black(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IBlack << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_red(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IRed << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_green(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IGreen << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_yellow(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IYellow << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_blue(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IBlue << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_purple(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IPurple << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_cyan(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::ICyan << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
	template <typename T>
	std::string print_white(T val, std::string prefix = "", std::string suffix = "") {
		std::string s = repr(val);
		std::cout << prefix << printcolors::IWhite << s << printcolors::Color_Off << suffix << std::endl;
		return s;
	}
}
#endif // PRETTYPRINT_HPP
