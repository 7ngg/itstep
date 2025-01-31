"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.routeNotFound = routeNotFound;
function routeNotFound(_req, res, _next) {
    res.status(404).json({ error: { message: "Route does not exist" } });
}
