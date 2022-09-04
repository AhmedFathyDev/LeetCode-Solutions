public class Solution {
    public IList<IList<string>> DisplayTable(IList<IList<string>> orders) {
        var tableDictionary = new Dictionary<string, int>[501];
 
        for (var tableNumber = 0; tableNumber < 501; ++tableNumber)
        {
            tableDictionary[tableNumber] = new Dictionary<string, int>();
        }
 
        var uniqueFoodItems = new HashSet<string>();
 
        foreach (var order in orders)
        {
            var tableNumber = Convert.ToInt32(order[1]);
            var foodItem = order[2];
 
            uniqueFoodItems.Add(foodItem);
 
            tableDictionary[tableNumber][foodItem] =
                tableDictionary[tableNumber].GetValueOrDefault(foodItem) + 1;
        }

        var foodItemsSorted = uniqueFoodItems.ToList();
        foodItemsSorted.Sort(StringComparer.Ordinal);

        var displayTable = new List<IList<string>>();
 
        for (var tableNumber = 0; tableNumber < 501; ++tableNumber)
        {
            if (tableNumber > 0 && tableDictionary[tableNumber].Count == 0)
            {
                continue;
            }
 
            var table = new List<string> { tableNumber == 0 ? "Table" : tableNumber.ToString() };
 
            table.AddRange(foodItemsSorted.Select(foodItem =>
                tableNumber == 0 ? foodItem : tableDictionary[tableNumber].GetValueOrDefault(foodItem).ToString()));
 
            displayTable.Add(table);
        }
 
        return displayTable;
    }
}