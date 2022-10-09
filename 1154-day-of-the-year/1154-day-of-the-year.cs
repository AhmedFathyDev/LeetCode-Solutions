public class Solution {
    public int DayOfYear(string date) {
        bool CheckYear(int year) {
            if (year % 400 == 0)
                return true;
            if (year % 100 == 0)
                return false;
            return year % 4 == 0;
        }
        
        var dateArr = date.Split('-');
        
        var year = int.Parse(dateArr[0]);
        var month = int.Parse(dateArr[1]);
        var day = int.Parse(dateArr[2]);
        
        var numberOfDays = 0;
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if (CheckYear(year))
        {
            days[1] = 29;
        }
        
        for (var i = 0; i < month - 1; ++i)
        {   
            numberOfDays += days[i];
        }
        
        return numberOfDays + day;
    }
}