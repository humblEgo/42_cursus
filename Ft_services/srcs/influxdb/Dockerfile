FROM alpine:latest

RUN apk add influxdb --no-cache

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/influxd"]