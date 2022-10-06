class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> finallist;
        finallist = new ArrayList<List<Integer>>();
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        List<Integer> alist = new ArrayList<>();
        list1.add(1);
        list2.add(1);
        alist.add(1);
        list2.add(1);
        alist.add(1);
        finallist.add(list1);
        finallist.add(list2);
        if (rowIndex == 1){
            return list2;
        }
        for (int j = 3;j <= rowIndex + 1;j++) {
            List<Integer> list3 = new ArrayList<>();
            list3.add(1);
            for (int i = 0; i < alist.size() - 1; i++) {
                list3.add(alist.get(i) + alist.get(i + 1));
            }
            list3.add(1);
            finallist.add(list3);
            alist.clear();
            alist.addAll(list3);
            if (rowIndex + 1 == j){
                return alist;
            }
        }
        return list1;
    }
}
