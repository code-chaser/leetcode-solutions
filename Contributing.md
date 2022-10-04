# Contributing Guidelines

This documentation contains a set of guidelines to help you during the contribution process. <br>
Please see this for [hacktoberfest contributors](https://github.com/code-chaser/leetcode-solutions/discussions/18)

# Submitting Contributions👩‍💻👨‍💻
Below you will find the process and workflow used to review and merge your changes.

## Step 1 : Fork the Project
- Fork this Repository. This will create a Local Copy of this Repository on your Github Profile. Keep a reference to the original project in `upstream` remote.
```
$ git clone https://github.com/<your-username>/leetcode-solutions
$ cd leetcode-solutions
$ git remote add upstream https://github.com/code-chaser/leetcode-solutions
```

- If you have already forked the project, update your copy before working.
```
$ git remote update
$ git checkout <branch-name>
$ git rebase upstream/<branch-name>
```
## Step 2 : Create a Branch

```
# It will create a new branch with name branch_name and switch to that branch 
$ git checkout -b <branch_name>
```
## Step 3 : Work on the leetcode problems
- Add all the code files in their correct folders.
- After you've made changes or made your contribution to the project add changes to the branch you've just created by:
```
# To add all new files to branch branch_name
$ git add .
```
## Step 4 : Commit

- To commit give a descriptive message for the convenience of reveiwer by:
```
# This message get associated with all files you have changed
$ git commit -m "message"
```

## Step 5 : Work Remotely
- Now you are ready to your work to the remote repository.
- When your work is ready and complies with the project conventions, upload your changes to your fork:

```
# To push your work to your remote repository
$ git push -u origin <branch_name>
```

## Step 6 : Pull Request
- Go to your repository in browser and click on compare and pull requests. 
  - Then add a title to your pull request.
  - Add ***Problem Statement Link*** and ***Your Submission Link*** for **each problem**.
  - The files should be named according to the [naming convention](https://github.com/code-chaser/leetcode-solutions/discussions/71).
  - There should be **atleast 3 problems** and at **max 5 problems** in one PR.
- Your Pull Request has been submitted and will be reviewed by the moderators and merged.🥳



