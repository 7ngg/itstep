import { Router } from "express";
import { create, getAll, getById, remove } from "../endpoints/users";

const router = Router({ mergeParams: true });

router.get("/", getAll);
router.get("/:id", getById);
router.post("/", create)
router.delete("/:id", remove);

export default router;
