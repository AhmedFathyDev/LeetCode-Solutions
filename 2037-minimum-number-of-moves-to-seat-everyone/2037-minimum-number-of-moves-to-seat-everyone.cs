public class Solution {
    public int MinMovesToSeat(int[] seats, int[] students) {
        Array.Sort(seats);
        Array.Sort(students);

        return seats.Select((seat, i) => Math.Abs(seat - students[i])).Sum();
    }
}