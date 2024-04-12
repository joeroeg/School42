- search and lists the largest files in your home directory: `find ~ -type f -exec du -h {} + | sort -rh | head -n 10`
- search and lists the largest files in entire file system: `sudo find / -type f -exec du -h {} + 2>/dev/null | sort -rh | head -n 10`
- serch and list the largest files on mac `find / -type f -exec du -h {} + 2>/dev/null | sort -rh | head -n 10`
- search for .git and delete: `find ./ -name .git -type d -exec echo {} \; -exec rm -ri {} \;`
- search and delete without confirmation: `find ./ -name .git -type d -exec rm -rf {} \;`
- generate a file and fill it with lines `for i in {1..10000}; do echo "file 1 line $i"; done > output_file.txt`



## Git
- to list local branches `git branch`
- to list remote branches `git branch -r`
- to delete a branch locally `git branch -d branch-name`
- to delete it from a remote repository `git push origin --delete branch-name`

### Submodules
Submodules allow you to keep projects in separate repositories but link them from a parent repository. This is particularly useful when projects are somewhat independent or will continue to be developed separately.

#### How to Use Submodules:
1. **Clone the primary repository:**
   ```bash
   git clone https://github.com/your-username/primary-repo.git
   cd primary-repo
   ```
2. **Add the secondary repository as a submodule:**
   ```bash
   git submodule add https://github.com/your-username/secondary-repo.git path/to/submodule
   git commit -m "Added secondary as a submodule."
   git push
   ```
   Replace `path/to/submodule` with the directory where you want the secondary repository to reside within the primary repository.

### Merge projects

Combining two GitHub projects into one while preserving all the commit history involves a few steps. This can be done by adding one project as a remote to the other and then merging the projects together. Here's a step-by-step guide on how to accomplish this, using Git commands:

#### Step 1: Choose the Primary Repository
Decide which of the two repositories will act as the primary repository — this is the one you'll merge the other repository into.

#### Step 2: Clone the Primary Repository
First, clone the primary repository to your local system. Open a terminal and run:
```bash
git clone https://github.com/your-username/primary-repo.git
cd primary-repo
```

#### Step 3: Add the Secondary Repository as a Remote
Add the second project as a remote to the cloned repository:
```bash
git remote add secondary https://github.com/your-username/secondary-repo.git
git fetch secondary
```

#### Step 4: Create a Branch for the Secondary Repository
To keep things organized and avoid conflicts in the master/main branch, create a new branch to pull in the secondary repository:
```bash
git checkout -b merge-secondary
```

#### Step 5: Merge the Secondary Repository into the New Branch
Now merge the secondary repository into this new branch, preserving all the commit history:
```bash
git merge secondary/main --allow-unrelated-histories
```
Replace `secondary/main` with the appropriate branch name if the main branch of the secondary repository is named differently (like `secondary/master`).

#### Step 6: Resolve Conflicts
If there are conflicts, Git will prompt you to resolve them. Open the conflicting files and make the necessary changes. After resolving conflicts, add the resolved files to the staging area using:
```bash
git add <resolved-file>
```
Then, continue the merge:
```bash
git commit -m "Resolved merge conflicts."
```

#### Step 7: Push the Changes
Once all conflicts are resolved and the local merge is complete, push the changes to the primary repository:
```bash
git checkout main
git merge merge-secondary
git push origin main
```

#### Step 8: Clean Up
If you wish, you can delete the branch created for merging:
```bash
git branch -d merge-secondary
```
And you might also want to remove the remote for the secondary repository:
```bash
git remote remove secondary
```

This method ensures that all commit histories from both repositories are preserved and combined into one repository. Be sure to perform these actions carefully to avoid losing any data. If you're unsure at any stage, consider making backup copies of both repositories before proceeding.
