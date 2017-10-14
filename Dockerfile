FROM node:8-wheezy

WORKDIR /usr/src/app

RUN npm i -g yarn 
# bs-platform

COPY package.json .
COPY yarn.lock .
COPY bsconfig.json .

RUN yarn

COPY src ./src
COPY test ./test
COPY webpack.config.js ./webpack.config.js

ENV NODE_ENV=production

RUN yarn build

EXPOSE 3000

CMD node lib/js/src/server.js


