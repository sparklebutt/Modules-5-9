/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:24:27 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/05 19:57:52 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
/**
 * @brief do we leave room for 2 fucntions, one to check string clean, then stoi
 * 
 */

class PmergeMe
{
	private:
		std::list<unsigned int> m_lst;
		std::vector<unsigned int> m_vec;
		void fillContainers(const std::string& set);
		// helper fucntion for insertion 
		template <typename Container>
		int insertPoint(const Container& cont, unsigned int key, int left, int right, int& comp);
		//insertion
		void insertionSortVec(std::vector<unsigned int>& vec, int left, int right);
		//void insertionSortDeque(std::deque<unsigned int>& deq);
		void insertionSortList(std::list<unsigned int>& lst);
		// helper fucntion for insertion 
		//int insertPointVec(const std::vector<unsigned int>& vec, unsigned int key, int left, int right, int& comp);
		//insertion
		//void insertionSortVec(std::vector<unsigned int>& vec, int left, int right);

	public:
		PmergeMe ();
		PmergeMe (const std::string& set);
		PmergeMe (PmergeMe &other) = delete;
		PmergeMe& operator=(PmergeMe &other) = delete;
		~PmergeMe ();
		void test();
		//double calculation();
};