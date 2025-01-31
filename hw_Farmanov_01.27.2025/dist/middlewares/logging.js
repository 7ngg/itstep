"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.logRequest = logRequest;
function logRequest(req, _res, next) {
    console.log(`[${new Date().toISOString()}] ${req.method} ${req.path}\t ${req.socket.remoteAddress}`);
    next();
}
