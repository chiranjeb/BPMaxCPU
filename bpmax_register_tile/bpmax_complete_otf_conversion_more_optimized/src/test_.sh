declare -a elems=(
    "2 192 48"
    "6 192 48"
    "6 480 48"
    "16 480 48"
    "10 480 48"
    "12 480 48"
    "7 480 96"
    "18 192 48"
    "10 384 96"
    "5 384 192"
    "2 384 192"
)



while true
do
    for elem in "${elems[@]}"; do
       read -a strarr <<< "$elem"  # uses default whitespace IFS
       echo "Running with input" ${strarr[0]} ${strarr[1]} ${strarr[2]}
       ./bpmax.verify-rand ${strarr[0]} ${strarr[1]} ${strarr[2]} 3 24
       if [ $? -eq 0 ]
       then
          echo "New program matches base program                      [PASS]"
       else
          echo "[FAIL] WriteC program doesn't match base program         [FAIL]"
        exit 1
      fi
     done
done
