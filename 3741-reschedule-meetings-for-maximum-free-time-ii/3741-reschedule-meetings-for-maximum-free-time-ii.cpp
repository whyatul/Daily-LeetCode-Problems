class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int N=startTime.size();
        vector<int>gaps;

        gaps.push_back(startTime[0]-0);

        for(int i=1;i<N;i++){
            gaps.push_back(startTime[i]-endTime[i-1]);
        }

        gaps.push_back(eventTime-endTime[N-1]);

        int n=gaps.size();
        vector<int>maxRight(n,0);
        vector<int>maxLeft(n,0);

        for(int i=n-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],gaps[i+1]);
        }

        for(int i=1;i<n;i++){
            maxLeft[i]=max(maxLeft[i-1],gaps[i-1]);
        }

        int ans=0;
        for(int i=1;i<n;i++){
            int currMeetingDuration=endTime[i-1]-startTime[i-1];

            // Move the meeting to another free spot
            if(currMeetingDuration<=max(maxLeft[i-1],maxRight[i])){
                ans=max(ans,currMeetingDuration+gaps[i-1]+gaps[i]);
            }

            // Merge left and right free time
            ans=max(ans,gaps[i-1]+gaps[i]);
        }
        return ans;
    }
};