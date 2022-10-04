class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> finallist = new ArrayList<List<Integer>>();
        if (numRows == 1){
            List<Integer> list1 = new ArrayList<>();
            list1.add(1);
            finallist.add(list1);
            return finallist;
        }
        else if (numRows == 2){
            List<Integer> list1 = new ArrayList<>();
            List<Integer> list2 = new ArrayList<>();
            list1.add(1);
            list2.add(1);
            list2.add(1);
            finallist.add(list1);
            finallist.add(list2);
            return finallist;
        }
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        ArrayList<Integer> alist = new ArrayList<>();
        list1.add(1);
        list2.add(1);
        alist.add(1);
        list2.add(1);
        alist.add(1);
        finallist.add(list1);
        finallist.add(list2);
        for (int j = 3;j <= numRows;j++) {
            List<Integer> list3 = new ArrayList<>();
            list3.add(1);
            for (int i = 0; i < alist.size() - 1; i++) {
                list3.add(alist.get(i) + alist.get(i + 1));
            }
            list3.add(1);
            finallist.add(list3);
            alist.clear();
            alist.addAll(list3);
        }
        return finallist;
    }
}