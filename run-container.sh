docker run --mount src="$(pwd)",target=/SceneGen,type=bind --rm scene-gen-image "cd SceneGen && ./build.sh"

#docker build -t sc-gen .