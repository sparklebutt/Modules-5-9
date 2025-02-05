/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:49:19 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/05 15:01:45 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "PmergeMe.hpp"
#include <sstream>

template<typename Container>
static void printContainer(const Container& cont) {
    for (const auto& elem : cont) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
void PmergeMe::test()
{
	std::cout<<"bug hunting 000\n";
	insertionSortVec(m_vec, 0, m_vec.size() - 1);
	std::cout<<"bug hunting \n";
	printContainer(m_vec);
} 
PmergeMe::PmergeMe() {std::cout<<"default constructor called\n";}

PmergeMe::PmergeMe(const std::string& set) {

	//fill vector and deq
	fillContainers(set);
	//printContainer(m_deq);
	//printContainer(m_vec);
	std::cout<<"default constructor called\n";
}

void PmergeMe::fillContainers(const std::string& set)
{
	std::istringstream tokens(set);
    std::string num;

	int convertedNum = 0;
	
	while (tokens >> num)
	{
		try
		{
			convertedNum = stoi(num);
			// if (convertedNum > or something) throw
			m_deq.push_back(convertedNum);
			m_vec.push_back(convertedNum);
		}
		catch(const std::exception& e)
		{
			std::cerr << "stoi failure in construction" << e.what() << '\n';
		}
	}	
}
PmergeMe::~PmergeMe() {std::cout<<"deconstructor called\n";}

void PmergeMe::insertionSortVec(std::vector<unsigned int>& vec, unsigned int left, unsigned int right) {
    //std::cout<<"bug hunting 111\n";
	if (vec.empty())
		throw std::runtime_error("vec was empty for some reason ");
	if (right < left)
		throw std::runtime_error("right is bigger than ölefty  ");
	for (unsigned int i = left + 1; i <= right; ++i) {
	    unsigned int key = vec[i];
		std::cout<<"key to insert = "<<key<<"\n";
        int j = i - 1;
	    while (j >= static_cast<int>(left) && vec[j] > key) {
            vec[j + 1] = vec[j];
			std::cout << "Shifting: ";
            for (const auto& num : vec) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
			--j;
        }
        vec[j + 1] = key;
		std::cout << "Array after inserting key: ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
// Helper function to insert in sorted order
/*template<typename Container>
void insertInOrder(Container& cont, typename Container::iterator start, typename Container::iterator end) {
    for (auto it = start; it != end; ++it) {
        auto pos = std::upper_bound(cont.begin(), it, *it);
        std::rotate(pos, it, it + 1);
    }
}
void mergeSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Recursively sort each half
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        
        // Merge the sorted halves
        std::inplace_merge(vec.begin() + left, vec.begin() + mid + 1, vec.begin() + right + 1);
	}
}
// Ford-Johnson sorting for vector
void fordJohnsonSort(std::vector<int>& vec) {
//    std::sort(vec.begin(), vec.end()); // Initial sort for demo purposes
	mergeSort(vec, vec.front(), vec.back());
    insertInOrder(vec, vec.begin(), vec.end());
}

// Ford-Johnson sorting for deque
void fordJohnsonSort(std::deque<int>& deq) {
    std::sort(deq.begin(), deq.end()); // Initial sort for demo purposes
	//mergeSort(deq, deq.front(), deq.back());
    insertInOrder(deq, deq.begin(), deq.end());
}*/

// Helper function to print a container


