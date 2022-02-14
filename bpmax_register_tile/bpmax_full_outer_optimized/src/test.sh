declare -a elems=(
    "1 40 4"
    "51 40 4"
    "100 64 8"
    "33 192 16"
    "8 60 8"
    "8 192 16"
    "2 192 48"
    "6 192 48"
    "6 480 48"
    "7 480 96"
    "38 192 48"
    "16 192 96"
    "22 384 96"
    "9 384 192"
    "2 384 192"
)



while true
do
    for elem in "${elems[@]}"; do
       read -a strarr <<< "$elem"  # uses default whitespace IFS
       echo "Running with input" ${strarr[0]} ${strarr[1]} ${strarr[2]}
       ./bpmax.verify-rand ${strarr[0]} ${strarr[1]} ${strarr[2]} 2 2
       if [ $? -eq 0 ]
       then
          echo "New program matches base program                      [PASS]"
       else
          echo "[FAIL] WriteC program doesn't match base program         [FAIL]"
        exit 1
      fi
     done
done
