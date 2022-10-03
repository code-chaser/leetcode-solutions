/*Question:-You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.*/

class Solution {
    // parent is the root of the tree
    int[] parent = new int[26];
    //size is used to make the tree degree lower
    int[] size = new int[26];
    public boolean equationsPossible(String[] equations) {
        // make themselves their parents
        for(int i = 0; i < 26; i++){
            size[i] = 1;
            parent[i] = i;
        }
        // if "a == b" connet the a, b
        for(String s: equations){
            if(s.charAt(1) == '='){
                int a = s.charAt(0) - 'a';
                int b = s.charAt(3) - 'a';
                connect(a, b);
            }
        }
        //if "a != b" check whether these two has been connected
        for(String s : equations){
            if(s.charAt(1) == '!'){
                int a = s.charAt(0) - 'a';
                int b = s.charAt(3) - 'a';
                if(checkConnection(a, b)) return false;
            }
        }
        return true;
    }
    public void connect(int a, int b){
        int roota = findRoot(a);
        int rootb = findRoot(b);
        if(roota == rootb) return;
        if(size[roota] >= size[rootb]){
            parent[rootb] = roota;
            size[roota] += size[rootb];
        }else{
            parent[roota] = rootb;
            size[rootb] += size[roota];
        }
    }
    public int findRoot(int a){
        while(parent[a] != a){
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    public boolean checkConnection(int a, int b){
        int roota = findRoot(a);
        int rootb = findRoot(b);
        if(roota == rootb) return true;
        return false;
    }

}
