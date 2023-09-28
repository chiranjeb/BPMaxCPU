declare -a elems=(
    "1 40 20"
    "1 64 32"
    "1 1920 960"
    "1000 40 20"
    "8 60 30"
    "8 1920 960"
    "7 1920 960"
    "6 1920 960"
    "10 1920 960"
    "12 1920 960"
    "9 3840 960"
    "5 3840 1920"
    "2 1920 960"
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
