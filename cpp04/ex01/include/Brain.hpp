#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <cstddef>

class Brain {
public:
	Brain(void);
	Brain(const Brain& other);
	~Brain(void);

	Brain&			operator=(const Brain& other);
	std::string&	operator[](std::size_t index);

	std::size_t	getSize(void) const;
	void		addIdea(const std::string& newIdea);

private:
	static const std::size_t	IDEA_CAP = 100;
	std::string					_ideas[Brain::IDEA_CAP];
	std::size_t					_size;
};

#endif
