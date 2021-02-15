docker run --mount src="$(pwd)",target=/SceneGen,type=bind --rm -it scene-gen-image /bin/bash

#docker build -t sc-gen .