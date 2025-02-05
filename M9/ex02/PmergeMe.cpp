/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:49:19 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/05 20:10:06 by shaboom          ###   ########.fr       */
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
	//TimeDiff1
	std::cout<<"insertion sort vecotr\n";
	//time stamp start
	insertionSortVec(m_vec, 0, m_vec.size() - 1);
	printContainer(m_vec);
	//time stamp end
	// take comparison time store in timeDiff1 
	insertionSortList(m_lst);
	printContainer(m_lst);
	// new start time
	std::cout<<"insertion sort deque\n";
} 
PmergeMe::PmergeMe() {std::cout<<"default constructor called\n";}

PmergeMe::PmergeMe(const std::string& set) {

	//fill vector and deq
	fillContainers(set);
	//printContainer(m_lst);
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
			m_lst.push_back(convertedNum);
			m_vec.push_back(convertedNum);
		}
		catch(const std::exception& e)
		{
			std::cerr << "stoi failure in construction" << e.what() << '\n';
		}
	}	
}
PmergeMe::~PmergeMe() {std::cout<<"deconstructor called\n";}

/**
 * @brief bit shifting here by 1 is the same as / 2
 * 
 * @param vec 
 * @param key 
 * @param left 
 * @param right 
 * @param comp 
 * @return unsigned int 
 */
template<typename Container>
int PmergeMe::insertPoint(const Container& cont, unsigned int key, int left, int right, int& comp) {
    while (left <= right) {
        comp++;
//		std::cout<<"when is right and out of bounds matching = "<<right<<"and left "<<left<<std::endl;
		//unsigned int mid = left + (right - left) / 2;
		unsigned int mid = left + ((right - left) >> 1);
        if (cont[mid] == key)
		{
			comp++;
            return mid + 1;			
		}
        else if (cont[mid] < key)
		{
			comp++;
            left = mid + 1;
		}
        else
            right = mid - 1;
    }
    return left;
}

/**
 * @brief Insertion sort is an algorithm that builds the sorted array one element at a time 
 * by taking each new element and inserting it into its correct position within the already sorted portion.
 * It repeatedly compares and shifts elements until the new element is in its proper place. Random placement would
 * for example no longer be an insertion sort. 
 * 
 * comparisons are any comparison in the sorting process. 
 * 
 * @param vec 
 * @param left 
 * @param right 
 * 	if (vec.empty())
		throw std::runtime_error("vec was empty for some reason ");
	if (right < left)
		throw std::runtime_error("right is bigger than ölefty  ");
 */

void PmergeMe::insertionSortVec(std::vector<unsigned int>& vec, int left, int right) {
	int comp = 0;

	for (int i = left + 1; i <= right; ++i) {
	    comp++;
		int key = vec[i];
		//std::cout<<"key to insert = "<<key<<"\n";
        int j = i - 1;
		//std::cout<<"when is j and out of bounds matching = "<<j<<"and left "<<left<<std::endl;
	    int pos = insertPoint(vec, key, left, j, comp);
		while (j >= pos) {
		    vec[j + 1] = vec[j];
			--j;
			comp++;
        }
        vec[j + 1] = key;
		/*std::cout << "Array after inserting key: ";
        for (const auto& num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;*/
        std::cout <<"comp count = "<<comp<< std::endl;
    }
}


void PmergeMe::insertionSortList(std::list<unsigned int>& lst) {
	int comp = 0;
	
    //if (lst.empty()) return; this check should happen before this fucntion 
    std::list<unsigned int>::iterator it = lst.begin();
    ++it;
    for (; it != lst.end(); ++it) {
        unsigned int key = *it;
		comp++;
        // Move backwards to find the correct position for 'key'
        std::list<unsigned int>::iterator insertionPoint = lst.begin();
        while (insertionPoint != it && *insertionPoint <= key) {
			comp += 2;
		    ++insertionPoint;
        }        
        // Shift elements and insert 'key' at the correct position
        std::list<unsigned int>::iterator k = it;
        while (k != insertionPoint) {
			comp++;
		    *k = *std::prev(k);
            --k;
        }
        *insertionPoint = key;
        // Debug output
        /*std::cout << "List after inserting key: ";
        for (const auto& num : lst) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
		}*/
	}
    std::cout <<"comp count list= "<<comp<< std::endl;
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


