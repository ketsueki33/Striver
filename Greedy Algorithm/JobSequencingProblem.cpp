#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// https://www.youtube.com/watch?v=LjPx4wQaRIs

struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};

class Solution {
   public:
    // Custom comparison function to sort jobs by profit in descending order.
    static bool myCmp(Job j1, Job j2) {
        return j1.profit > j2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        // Sort the array of jobs in descending order of profit.
        sort(arr, arr + n, myCmp);

        // Initialize a vector to track time slots, initially all false.
        vector<bool> timeSlots(n, false);
        timeSlots[0] = true;  // no job can have 0 as deadline

        // Mark the time slot of the first job's deadline as scheduled and include it in the answer
        int count = 1, profit = arr[0].profit;
        timeSlots[arr[0].dead] = true;

        // Iterate through the sorted jobs to schedule them.
        for (int i = 1; i < n; i++) {
            int time = arr[i].dead;

            // Find an available time slot for the current job.
            while (time > 0) {
                if (!timeSlots[time]) {
                    // Schedule the job, update profit and count, and break the loop.
                    timeSlots[time] = true;
                    profit += arr[i].profit;
                    count++;
                    break;
                } else {
                    // If the time slot is occupied, try the previous slot.
                    time--;
                }
            }
        }

        // Return the count of scheduled jobs and the total profit.
        return {count, profit};
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}