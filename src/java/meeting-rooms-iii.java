class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, new Comparator<int[]>() {
            @Override
            public int compare (int[] a, int [] b) {
                return a[0] - b[0];
            }
        });
        PriorityQueue<Room> q = new PriorityQueue<>(new Comparator<Room>() {
            @Override
            public int compare (Room r1, Room r2) {
                if (r1.end == r2.end) {
                    return r1.index - r2.index;
                }
                else {
                    if (r1.end >= r2.end) {
                        return 1;
                    }
                    else {
                        return -1;
                    }
                }
            }
        });
        
        for (int i = 0; i<n; i++) {
            q.add(new Room(0, 0, 0, i));
        }
        
        for (int[] meeting : meetings) {
            
            Room meetingRoom = findRoom(meeting[0], new ArrayList<>(q));
            if (meetingRoom == null) {
                meetingRoom = q.poll();
            }
            else {
                q.remove(meetingRoom);
            }
            
            if (meetingRoom.end <= meeting[0]) {
                // use room without delay
                q.add(new Room(meeting[0], meeting[1], meetingRoom.freq+1, meetingRoom.index));
            }
            else {
                q.add(new Room(meetingRoom.end, meetingRoom.end - meeting[0] + meeting[1], meetingRoom.freq+1, meetingRoom.index));
            }
        }
        
        long freq = 0;
        
        for (Room room: q) {
            freq = Math.max(freq, room.freq);
        }
        long index = Long.MAX_VALUE;
        for (Room room: q) {
            // System.out.println(room.index + " " + room.freq);
            if (room.freq == freq) {
                index = Math.min(room.index, index);
            }
        }
        return (int)index;
    }
    private Room findRoom(int start, List<Room> r) {
//         int i = 0;
//         int j = r.size()-1;
        
//         Room ans = null;
//         while (i <= j) {
//             int m = i + (j-i)/2;
//             if (r.get(m).end <= start) {
//                 ans = r.get(m);
//                 j = m-1;
//             }
//             else {
//                 i = m+1;
//             }
//         }
//         return ans;
        long index = Long.MAX_VALUE;
        Room ans = null;
        for (Room a: r) {
            if (a.end <= start) {
                if (a.index < index) {
                    index = a.index;
                    ans = a;
                }
            }
        }
        return ans;
    }
}
class Room {
    long start;
    long end;
    long freq;
    int index;
    public Room (long start, long end, long freq, int index) {
        this.start = start;
        this.end = end;
        this.freq = freq;
        this.index = index;
    }
}
// Submission Link: https://leetcode.com/problems/meeting-rooms-iii/submissions/790982792/