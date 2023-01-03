declare -a elems=(
    #"1 40 4"
    #"51 40 4"
    #"100 64 8"
    #"33 192 16"
    #"8 60 8"
    #"8 192 16"
    "1 192 48"
    "1 192 48"
    "1 193 48"
    "1 194 48"
    "1 195 48"
    "1 196 48"
    "1 480 48"
    "1 480 96"
    "1 192 48"
    "1 193 48"
    "1 194 48"
    "1 195 48"
    "1 196 48"
    "1 196 48"
    "1 1000 48"
    "1 1965 48"
    "1 1906 48"
    "1 197 96"
    "1 384 96"
    "1 385 96"
    "1 386 96"
    "1 387 96"
    "1 388 96"
    "1 384 192"
    "1 385 192"
    "1 386 192"
    "1 387 192"
    "1 387 192"
    "1 389 192"
    "1 384 192"
    "1 2000 192"
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
