;;; Colby Rush, CS 210 HW #3, Lisp Assignment
;;; Sequential is still not working, but it's much better than the previous versions I gave you.

(defun sum (L)
  (reduce '+ L))

(defun counter (x L)
  (count x L))

(defun number-of (L x)
  (setf count 0)
  (setf count (count x L))
  (setf y (* x count))
  (return-from number-of y))

(defun three-same (L)
  (setf b (sum L))
  (setf a 0)
  (loop for g from 1 to 6 do
        (setf a (counter g L))
        (if (> a 2) (return-from three-same b))))

(defun four-same (L)
  (setf b (sum L))
  (setf a 0)
  (loop for g from 1 to 6 do
        (setf a (counter g L))
        (if (> a 3) (return-from four-same b))))

(defun three-and-two (L)
  (setf a 0)
  (setf b 0)
  (setf c 0)
  (setf d 0)
  (loop for g from 1 to 6 do
        (setf a (counter g L))
        (if (= a 3) (setf c 1)))
  (loop for g from 1 to 6 do
        (setf b (counter g L))
        (if (= b 2) (setf d 2)))
  (if (< c d) (return-from three-and-two 25)))

(defun semisequential (L)
  (setf count 0)
  (setf a 0)
  (sort L #'<)
  (let ((len (length L))))
  (loop for g from 1 to 6 do
        (if (find g L) (incf a)))
  (if (> a 4) (return-from semisequential 30)))

(defun sequential (L)
  (setf count 0)
  (setf a 0)
  (sort L #'<)
  (let ((len (length L))))
  (loop for g from 1 to 6 do
        (if (find g L) (incf a)))
  (if (= a 5) (return-from sequential 40)))

(defun all-same (L)
  (setf a 0)
  (loop for g from 1 to 6 do
        (setf a (counter g L))
        (if (= a 5)
            (return-from all-same 50))))

(defun sum-of (L)
  (setq a (apply '+ L))
  (return-from sum-of a))

(defun most-frequent (L)
  (setf a 0)
  (setf b 0)
  (loop for g from 1 to 6 do
        (if (< b (count g L))
            (setf a g))
        (if (= b (count g L))
            (if (< a g)
                (setf a g)))
        (if (< b (count g L))
            (setf b (count g L))))
  (return-from most-frequent a))

(defun categorize (L)
  (setf i 0)
  (setf p 0)
  (setf counter 7)
  (setf a (apply #'three-same (L)))
  (setf b (apply #'four-same (L)))
  (setf c (apply #'three-and-two (L)))
  (setf d (apply #'semisequential (L)))
  (setf e (apply #'sequential (L)))
  (setf f (apply #'all-same (L)))
  (setf g (apply #'sum-of (L)))
  (setf h (apply #'most-frequent (L)))
  (loop for z from a to h do
        (if (> z i) (setf i z))
        (if (> z p) (setf p counter))
        (if (= counter 13) (setf counter -1))
        (incf counter))
  (return-from categorize p))