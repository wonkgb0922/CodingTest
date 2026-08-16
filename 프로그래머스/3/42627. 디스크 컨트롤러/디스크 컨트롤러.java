import java.util.*;

class Solution {
    static int n;
    public int solution(int[][] jobs) {
        PriorityQueue<Job> jobpq = new PriorityQueue<>(
            (job1, job2) -> Integer.compare(job1.start, job2.start)
        );
        PriorityQueue<Job> pq = new PriorityQueue<>();
        int sum = 0;
        n = jobs.length;
        int cur = 0;
        for(int i = 0; i < n; i++)
            jobpq.offer(new Job(i, jobs[i][0], jobs[i][1]));
        while(!jobpq.isEmpty()) {
            if(jobpq.peek().start <= cur) {
                pq.offer(jobpq.poll());
                continue;
            }
            if(pq.isEmpty()) {
                cur = jobpq.peek().start;
                pq.offer(jobpq.poll());
                continue;
            }
            Job temp = pq.poll();
            cur += temp.time;
            sum += cur - temp.start;
        }
        while(!pq.isEmpty()) {
            Job temp = pq.poll();
            cur = Math.max(cur, temp.start) + temp.time;
            sum += cur - temp.start;
        }
        return sum / n;
    }
}

class Job implements Comparable<Job> {
    public Job(int idx, int start, int time) {
        this.idx = idx;
        this.start = start;
        this.time = time;
    }
    
    @Override
    public int compareTo(Job job) {
        if(this.time == job.time) {
            if(this.start == job.start)
                return Integer.compare(this.idx, job.idx);
            return Integer.compare(this.start, job.start);
        }
        return Integer.compare(this.time, job.time);
    }
    public int idx;
    public int start;
    public int time;
}