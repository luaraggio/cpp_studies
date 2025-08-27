#include <exception>
#include <iostream>

class	custom_exception: public std::exception {
	virtual	const char* what() const noexcept {
		return "Custom Exception";
	}
};

void	my_function2() {
	throw 5.6;
}

void	my_function1() {
	my_function2();
}

int	main(void) {
	std::string word = "four";

	// std::cout << word.at(7) << std::endl;

	try {
		// std::cout << word.at(4) << std::endl;
		// int	*array = new int[9999999999999999];
		// throw std::exception();
		// throw std::runtime_error("Problem here!");
		// throw custom_exception();
		// throw 20;
		// throw "luara";
		// throw 5.6;
		my_function1();
	}
	catch (std::out_of_range& e) {
		std::cout << "First exception thrown: " << e.what() << std::endl;
	}
	catch (std::bad_alloc& e) {
		std::cout << "Second exception thrown: " << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	catch (int code) {
		std::cout << "Error code: " << code << std::endl;
	}
	catch (...) {
		std::cout << "Default catch case!" << std::endl;
	}
	return (0);
}
