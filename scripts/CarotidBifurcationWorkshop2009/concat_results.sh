
# getting training results together for openoffice
# to run from the base data directory


# center 0 data 0-8
cat results/challenge00{0,1,2,3,4,5,6,7,8}/lum*.txt > results_0.txt 
sed -i 's/\./,/g' results_0.txt  
sed -i 's/ /\t/g' results_0.txt

# center 1 data 0-2
cat results/challenge10{0,1,2}/lum*.txt > results_1.txt 
sed -i 's/\./,/g' results_1.txt  
sed -i 's/ /\t/g' results_1.txt

# center 2 data 0-2
cat results/challenge20{0,1,2}/lum*.txt > results_2.txt 
sed -i 's/\./,/g' results_2.txt  
sed -i 's/ /\t/g' results_2.txt

