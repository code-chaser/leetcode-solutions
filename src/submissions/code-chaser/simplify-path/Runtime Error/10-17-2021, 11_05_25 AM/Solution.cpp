// https://leetcode.com/problems/simplify-path

/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~
--||author : codechaser||-- 
~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
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
                if(simplifiedPath.size()) simplifiedPath.pop_back();
                continue;
            }
            if(temp == ".") continue;
            
            simplifiedPath.append(temp);
        }
        if(simplifiedPath.back() == '/') simplifiedPath.pop_back();
        return simplifiedPath.size()?simplifiedPath:"/";
    }
};
/*
    |---------------------------------------------------|
    |||   https://codeforces.com/profile/codechaser   |||
    |||   https://www.codechef.com/users/codechaser   |||
    |||        https://github.com/code-chaser         |||
    |---------------------------------------------------|
*/