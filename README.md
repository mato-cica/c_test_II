# c_test_II
C programming language test made by codility.com service. Task to do is:

How many officers should salute their superiors if each salute only the officers who are one rank up?
Given is a set of officers with their ranks as ranks[]. 

ranks[] have a range of 2 - 100,000, and members of ranks[] are form 0 to 1,000,000,000.
Write a function:

                      int solution(int ranks[], int N)
                      
For example: 
if is given ranks[] = [3, 5, 3, 0, 4, 2, 3, 0, 1] solution is 8 (2 officers with rank 0 salute officer with rank 1, 1 officer with rank 1 salutes 1 officer with rank 2,1 officer with rank 2 salutes 3 officers with rank 3, 3 officers with rank 3 salutes oficer with rank 4, and 1 officer with rank 4 salutes officer with rank 5);

if is given ranks[] = [3, 5, 3, 0] solution is 0 (there is no officers with one rank up).


