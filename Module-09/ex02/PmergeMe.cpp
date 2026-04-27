#include "PmergeMe.hpp"

#include <algorithm>
#include <cstddef>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vecResult = other._vecResult;
        this->_deqResult = other._deqResult;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int>& PmergeMe::getVecResult() const { return _vecResult; }

const std::deque<int>& PmergeMe::getDeqResult() const { return _deqResult; }

int PmergeMe::_getJacobsthal(int n) const
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int curr = 0;
    int prev = 1;
    int pprev = 0;

    for (int x = 2; x <= n; ++x)
    {
        curr = prev + 2 * pprev;
        pprev = prev;
        prev = curr;
    }
    return curr;
}

void PmergeMe::sortVector(const std::vector<int>& in)
{
    if (in.empty()) return;
    vvec C;
    for (size_t x = 0; x < in.size(); ++x)
    {
        std::vector<int> box;
        box.push_back(in[x]);
        C.push_back(box);
    }
    _sort(C);

    _vecResult.clear();
	for (size_t i = 0; i < C.size(); ++i)
    {
        if (!C[i].empty()) {
            _vecResult.push_back(C[i].front());
        }
    }
}

void PmergeMe::_sort(vvec& C)
{
    if (C.size() <= 1)
    {
        return;
    }
    std::vector<int> leftover;

    if (C.size() % 2 != 0)
    {
        leftover = C.back();
        C.pop_back();
    }

    vvec level;
    for (size_t x = 0; x < C.size(); x += 2)
    {
        std::vector<int> A = C[x];
        std::vector<int> B = C[x + 1];

        if (A.front() < B.front()) std::swap(A, B);

        A.insert(A.end(), B.begin(), B.end());
        level.push_back(A);
    }

    _sort(level);

    C.clear();
    vvec pend_chain;

    size_t pair_size = level.front().size() / 2;
    for (size_t x = 0; x < level.size(); ++x)
    {
        std::vector<int> winner(level[x].begin(), level[x].begin() + pair_size);
        C.push_back(winner);

        std::vector<int> loser(level[x].begin() + pair_size, level[x].end());
        pend_chain.push_back(loser);
    }

    _insertJacobsthal(C, pend_chain, leftover);
}

void PmergeMe::_insertJacobsthal(vvec& main_chain, vvec& pend_chain, std::vector<int>& leftover)
{
    if (pend_chain.empty()) return;

    main_chain.insert(main_chain.begin(), pend_chain[0]);

    int J = 3;
    int insert_count = 1;

    while (insert_count < (int)pend_chain.size())
    {
        int curr_j = _getJacobsthal(J);
        int prev_j = _getJacobsthal(J - 1);

        int end_p = std::min(curr_j, (int)pend_chain.size());

        for (int x = end_p; x > prev_j; --x)
        {
			std::vector<int>& b_k = pend_chain[x - 1];

			vvec::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), b_k);
			main_chain.insert(pos, b_k);
			insert_count++;
        }
		J++;
    }
	if (!leftover.empty()) {
		vvec::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), leftover);
		main_chain.insert(pos, leftover);
	}
}
// vec algo end

void PmergeMe::sortDeque(const std::vector<int>& in)
{
    if (in.empty()) return;
    vdeq C;
    for (size_t x = 0; x < in.size(); ++x)
    {
        std::deque<int> box;
        box.push_back(in[x]);
        C.push_back(box);
    }
    _sort(C);

    _deqResult.clear();
    for (size_t i = 0; i < C.size(); ++i)
    {
        if (!C[i].empty()) {
            _deqResult.push_back(C[i].front());
        }
    }
}

void PmergeMe::_sort(vdeq& C)
{
    if (C.size() <= 1)
    {
        return;
    }
    std::deque<int> leftover;

    if (C.size() % 2 != 0)
    {
        leftover = C.back();
        C.pop_back();
    }

    vdeq level;
    for (size_t x = 0; x < C.size(); x += 2)
    {
        std::deque<int> A = C[x];
        std::deque<int> B = C[x + 1];

        if (A.front() < B.front()) std::swap(A, B);

        A.insert(A.end(), B.begin(), B.end());
        level.push_back(A);
    }

    _sort(level);

    C.clear();
    vdeq pend_chain;

    size_t pair_size = level.front().size() / 2;
    for (size_t x = 0; x < level.size(); ++x)
    {
        std::deque<int> winner(level[x].begin(), level[x].begin() + pair_size);
        C.push_back(winner);

        std::deque<int> loser(level[x].begin() + pair_size, level[x].end());
        pend_chain.push_back(loser);
    }

    _insertJacobsthal(C, pend_chain, leftover);
}

void PmergeMe::_insertJacobsthal(vdeq& main_chain, vdeq& pend_chain, std::deque<int>& leftover)
{
    if (pend_chain.empty()) return;

    main_chain.insert(main_chain.begin(), pend_chain[0]);

    int J = 3;
    int insert_count = 1;

    while (insert_count < (int)pend_chain.size())
    {
        int curr_j = _getJacobsthal(J);
        int prev_j = _getJacobsthal(J - 1);

        int end_p = std::min(curr_j, (int)pend_chain.size());

        for (int x = end_p; x > prev_j; --x)
        {
            std::deque<int>& b_k = pend_chain[x - 1];

            vdeq::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), b_k);
            main_chain.insert(pos, b_k);
            insert_count++;
        }
        J++;
    }
    if (!leftover.empty()) {
        vdeq::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), leftover);
        main_chain.insert(pos, leftover);
    }
}