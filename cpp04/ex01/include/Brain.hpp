#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <cstddef>
# include <ostream>

class Brain {
public:
	Brain(void);
	Brain(const Brain& other);
	~Brain(void);

	Brain&				operator=(const Brain& other);
	const std::string&	operator[](std::size_t index) const;

	std::size_t	getSize(void) const;
	void		addIdea(const std::string& newIdea);
	bool		isEmpty(void) const;
	bool		hasSpaceLeft(void) const;

	static const std::size_t	CAPACITY = 100;

private:
	std::string					_ideas[Brain::CAPACITY];
	std::size_t					_size;
};

std::ostream&	operator<<(std::ostream& os, const Brain& brain);

#endif
