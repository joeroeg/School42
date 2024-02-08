- search and lists the largest files in your home directory: `find ~ -type f -exec du -h {} + | sort -rh | head -n 10`
- search and lists the largest files in entire file system: `sudo find / -type f -exec du -h {} + 2>/dev/null | sort -rh | head -n 10`
- search for .git and delete: `find /path/to/search -name .git -type d -exec echo {} \; -exec rm -ri {} \;`
- gcc -fsanitize=address


# Submodule
If the inner repository (minishell_february) is meant to be a part of the outer repository (42) but maintain its own separate Git history and contributions, consider using Git submodules. A submodule allows you to keep a Git repository as a subdirectory of another Git repository. This way, each repository can be updated independently, but you can still track the specific commit of the inner repository that the outer repository should point to.

``` shell
cd /Users/hezhukov/Desktop/42/maincourse/
git submodule add <repository-url> minishell_february
git commit -m "Added minishell_february as a submodule."
git push
```

If minishell_february was added to your repository but not as a submodule, you need to remove it from the index and commit that change. Ensure that you back up any important changes, as these steps will remove the directory from tracking (but not from your filesystem).

``` shell
git rm --cached minishell_february -r
git commit -m "Remove minishell_february from index"
```
