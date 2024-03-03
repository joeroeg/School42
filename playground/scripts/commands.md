- search and lists the largest files in your home directory: `find ~ -type f -exec du -h {} + | sort -rh | head -n 10`
- search and lists the largest files in entire file system: `sudo find / -type f -exec du -h {} + 2>/dev/null | sort -rh | head -n 10`
- search for .git and delete: `find ./ -name .git -type d -exec echo {} \; -exec rm -ri {} \;`
- search and delete without confirmation: `find ./ -name .git -type d -exec rm -rf {} \;`
- generate a file and fill it with lines `for i in {1..10000}; do echo "file 1 line $i"; done > output_file.txt`

