// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        string simplifiedPath;
        stringstream str(path);
        string temp;
        while(getline(str, temp, '/')) {
            if(simplifiedPath.back() != '/') simplifiedPath.push_back('/');
            if(temp == "..") {
                simplifiedPath.pop_back();
                while(simplifiedPath.back() != '/' && simplifiedPath.size()) simplifiedPath.pop_back();
                simplifiedPath.pop_back();
                continue;
            }
            if(temp == ".") continue;
            simplifiedPath.append(temp);
        }
        return simplifiedPath;
    }
};