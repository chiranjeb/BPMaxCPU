declare -a elems=(
    #"1 40 4"
    #"51 40 4"
    #"100 64 8"
    #"33 192 16"
    #"8 60 8"
    #"8 192 16"
    "2 192 48"
    "6 192 48"
    "6 193 48"
    "6 194 48"
    "6 195 48"
    "6 196 48"
    "6 480 48"
    "7 480 96"
    "18 192 48"
    "18 193 48"
    "18 194 48"
    "18 195 48"
    "18 196 48"
    "16 197 96"
    "10 384 96"
    "10 385 96"
    "10 386 96"
    "10 387 96"
    "10 388 96"
    "5 384 192"
    "6 385 192"
    "6 386 192"
    "6 387 192"
    "6 387 192"
    "6 389 192"
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
