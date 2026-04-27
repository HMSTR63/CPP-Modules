#pragma once

#include <sys/time.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

class PmergeMe
{
   public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortVector(const std::vector<int>& input);
    void sortDeque(const std::vector<int>& input);

    const std::vector<int>& getVecResult() const;
    const std::deque<int>& getDeqResult() const;

   private:
    typedef std::vector<std::vector<int> > vvec;
    typedef std::deque<std::deque<int> > vdeq;

    std::vector<int> _vecResult;
    std::deque<int> _deqResult;

    void _sort(vvec& C);
    void _sort(vdeq& C);

    void _insertJacobsthal(vvec& main_chain, vvec& pend_chain, std::vector<int>& leftover);
    void _insertJacobsthal(vdeq& main_chain, vdeq& pend_chain, std::deque<int>& leftover);

    int _getJacobsthal(int n) const;
};
