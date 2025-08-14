#include <iostream>
#include <vector>
using namespace std;

class VectorCounter {
   private:
    vector<int> _end;
    vector<int> _current;

   public:
    VectorCounter(const vector<int>& end) noexcept {
        this->_current = vector<int>(end.size(), 0);
        this->_end = end;
    }

    VectorCounter& operator++() noexcept {
        bool moved = false;
        for (int i = this->_end.size() - 1; i >= 0; i--) {
            if (this->_current[i] < this->_end[i]) {
                this->_current[i] += 1;
                return *this;
            }
        }
    }
};