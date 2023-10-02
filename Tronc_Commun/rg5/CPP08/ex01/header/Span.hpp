/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:10:09 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 20:10:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span {
    private:

        unsigned int _n;
        std::vector<int> _v;
        
    public:

        Span();
        Span(unsigned int n);
        Span(Span const &other);
        ~Span();

        Span &operator=(Span const &other);

        void addNumber(int n);
        int shortestSpan(void);
        int longestSpan(void);
        
        class NoSpanException : public std::exception {
            virtual const char *what() const throw();
        };
};

#endif