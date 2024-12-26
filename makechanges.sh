rm -f *.pdf 
python3 build_contents.py > contents.tex 
make gen 
find . -type f -regextype posix-extended -regex '^.+\.(aux|toc|bcf|blg|bbl|log|xml|out)$' -delete 
