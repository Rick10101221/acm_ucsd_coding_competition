#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Interval {
  public:
    int start = 0;
    int end = 0;
    int daysToComplete = 0;
    
    Interval(int start, int end, int daysToComplete) {
        this->start = start;
        this->end = end;
        this->daysToComplete = daysToComplete;
    }
};

struct compare {
    bool operator() (Interval* a, Interval* b) {
        if (a->start != b->start) return a->start < b->start;
        return a->end > b->end;
    }
};



int main() {
    int tasks, freeDays = 0, lastDay = 0;
    priority_queue<Interval*, vector<Interval*>, compare> pq;
    deque<Interval*> jobs;
    cin >> tasks;
    if (tasks == 0) {
        return 0;
    }
    for (int i = 0; i < tasks; i++) {
        int start, end, daysToComplete;
        cin >> start >> end >> daysToComplete;
        jobs.push_back(new Interval(start, end, daysToComplete));
        lastDay = max(lastDay, end);
    }
    sort(jobs.begin(), jobs.end(), [](Interval* a, Interval* b) { return a->start < b->start; });
    
    for (int i = 0; i < lastDay; i++) {
        while (!jobs.empty() && jobs.front()->start == i) {
            pq.push(jobs.front());
            jobs.pop_front();
        }
        //cout << "day " << i << endl;
        //cout << "pqSizeAfterPush: " << pq.size() << endl;
        if (!pq.empty()) {
            bool popped = false;
            while (!pq.empty() && pq.top()->start <= i) {
                //cout << "currentInterval: " << pq.top()->start << " " << pq.top()->end << " " << pq.top()->daysToComplete << endl;
                pq.top()->start++;
                if (!popped) {
                    
                    pq.top()->daysToComplete--;
                    popped = true;
                }
                if (pq.top()->daysToComplete == 0) {
                    //cout << "popping: " << pq.top()->start << " " << pq.top()->end << " " << pq.top()->daysToComplete << endl;
                    pq.pop();
                } else if (pq.top()->daysToComplete + pq.top()->start > pq.top()->end) {
                    cout << 'f';
                    return 0;
                }
                //cout << "currentIntervalAfterAlt: " << " " << pq.top()->start << " " << pq.top()->end << " " << pq.top()->daysToComplete << endl;
            }
        } else {
            //cout << "incrementing" << endl;
            freeDays++;
        }
    }
    cout << freeDays;
    return 0;
}
